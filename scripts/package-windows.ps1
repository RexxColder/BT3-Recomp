# Thin wrapper: package an existing Windows build without rebuilding anything.
#
#   scripts\package-windows.ps1                      # default output dir
#   scripts\package-windows.ps1 -Output D:\release   # custom output dir
#
# Reuses the runner already built under build/ (pass -SkipSetup semantics are implicit: --stage 4
# --skip-setup), runs the PE gate and writes the zip + sha256.
[CmdletBinding()]
param(
    [string]$Output,
    [Parameter(ValueFromRemainingArguments = $true)][string[]]$Extra
)
$ErrorActionPreference = 'Stop'
$ROOT = Split-Path -Parent $PSScriptRoot

$argv = @("$ROOT\games\bt3\setup.py", '--stage', '4', '--skip-setup', '--package')
if ($Output) { $argv += @('--output', $Output) }
if ($Extra) { $argv += $Extra }

Write-Host "== scripts/package-windows.ps1 -> python $($argv -join ' ')"
& python @argv
exit $LASTEXITCODE
