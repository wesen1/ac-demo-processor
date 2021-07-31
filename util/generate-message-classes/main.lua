---
-- @author wesen
-- @copyright 2021 wesen <wesen-ac@web.de>
--

local unpack = unpack or table.unpack

local function getLinesInFile(_filePath)

  local lines = {}
  for line in io.lines(_filePath) do
    table.insert(lines, line)
  end

  return lines

end

local function extractNextMessageHandlingBlock(_lines)

  local startLine, endLine

  local firstCaseStatementFound = false
  local firstBreakStatementFound = false
  for i, line in ipairs(_lines) do

    if (not firstCaseStatementFound) then
      if (line:match(" *case +[^:]+:")) then
        firstCaseStatementFound = true
        startLine = i
      end

    elseif (not firstBreakStatementFound) then
      if (line:match("break;")) then
        firstBreakStatementFound = true
      end

    else
      if (line:match("%s*case +[^:]+:")) then
        endLine = i - 1
        break
      end

    end

  end

  local blockLines, remainingLines
  if (startLine ~= nil and endLine ~= nil) then
    blockLines = { unpack(_lines, startLine, endLine) }
    remainingLines = { unpack(_lines, endLine + 1, #_lines) }

  else
    blockLines = {}
    remainingLines = _lines
  end

  return blockLines, remainingLines

end

local function extractNextMessageClassData(_lines)

  local blockLines, remainingLines = extractNextMessageHandlingBlock(_lines)

  if (#blockLines > 0) then

    local caseStatement = blockLines[1]
    local messageConstantName = caseStatement:match("case ([^:]+):")

    local startLine
    for i, line in ipairs(blockLines) do
      if (not line:match("case [^:]+:")) then
        startLine = i
        break
      end
    end

    local code = { unpack(blockLines, startLine, #blockLines) }

    local data = {
      messageConstantName = messageConstantName,
      code = code
    }

    return data, remainingLines

  else
    return nil, _lines
  end

end

local function convertMessageConstantToClassName(_messageConstantName)

  local className
  if (_messageConstantName:match("^SV_")) then
    className = _messageConstantName:sub(4)
  else
    className = _messageConstantName
  end

  className = className:sub(1, 1):upper() .. className:sub(2):lower()

  return className

end

local function generateNextMessageTemplateData(_lines)

  local data, remainingLines = extractNextMessageClassData(_lines)

  local templateData
  if (data) then
    local className = convertMessageConstantToClassName(data["messageConstantName"])

    templateData = {
      MESSAGE_CLASS_NAME = className,
      MESSAGE_CLASS_HEADER_FILE_NAME = className .. ".h",
      MESSAGE_IDENTIFIER = className:upper(),
      MESSAGE_CONSTANT_NAME = data["messageConstantName"],
      MESSAGE_HANDlER_CODE = table.concat(data["code"], "\n")
    }
  end

  return templateData, remainingLines

end

local function fillTemplateWithVariables(_template, _templateData)

  local renderedTemplate = _template
  for key, value in pairs(_templateData) do
    renderedTemplate = renderedTemplate:gsub("{{" .. key .. "}}", value)
  end

  return renderedTemplate

end

local function writeGeneratedCodeToFile(_outputDirectoryPath, _fileName, _code)

  local filePath = _outputDirectoryPath .. "/" .. _fileName

  local file = io.open(filePath, "w")
  file:write(_code .. "\n")
  file:close()

end

local function generateHeaderFileFromTemplateData(_headerTemplate, _templateData, _outputDirectoryPath)

  local headerFileName = _templateData["MESSAGE_CLASS_NAME"] .. ".h"
  local headerCode = fillTemplateWithVariables(_headerTemplate, _templateData)

  writeGeneratedCodeToFile(_outputDirectoryPath, headerFileName, headerCode)

end

local function generateCppFileFromTemplateData(_cppTemplate, _templateData, _outputDirectoryPath)

  local cppFileName = _templateData["MESSAGE_CLASS_NAME"] .. ".cpp"
  local cppCode = fillTemplateWithVariables(_cppTemplate, _templateData)

  writeGeneratedCodeToFile(_outputDirectoryPath, cppFileName, cppCode)

end

local function generateClassFromTemplateData(_outputDirectoryPath, _templateData, _headerTemplate, _cppTemplate)

  generateHeaderFileFromTemplateData(_headerTemplate, _templateData, _outputDirectoryPath)
  generateCppFileFromTemplateData(_cppTemplate, _templateData, _outputDirectoryPath)

end


local function generateMessageClasses(_outputDirectoryPath, _headerTemplate, _cppTemplate)

  local lines = getLinesInFile("switch-case.txt")

  while (true) do
    local templateData, remainingLines = generateNextMessageTemplateData(lines)
    if (templateData == nil) then
      break
    end

    generateClassFromTemplateData(_outputDirectoryPath, templateData, _headerTemplate, _cppTemplate)
    lines = remainingLines
  end

end


local outputDirectoryPath = "../../source/src/demoparser/MessageStream/Messages"
local cppTemplate = table.concat(getLinesInFile("MessageTemplate.cpp"), "\n")
local headerTemplate = table.concat(getLinesInFile("MessageTemplate.h"), "\n")

generateMessageClasses(outputDirectoryPath, headerTemplate, cppTemplate)

print("OK")
