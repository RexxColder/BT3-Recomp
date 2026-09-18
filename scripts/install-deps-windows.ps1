# Thin wrapper: install the Windows build dependencies only (stage 2).
#
#   scripts\install-deps-windows.ps1
#
# Prints the platform report, then asks before each install (winget/pip/aqt/download) and shows the
# exact command. Safe to re-run: everything already present is skipped.
[CmdletBinding()]
param(
    [Parameter(ValueFromRemainingArguments = $true)][string[]]$Extra
)
$ErrorActionPreference = 'Stop'
$ROOT = Split-Path -Parent $PSScriptRoot

$argv = @("$ROOT\games\bt3\setup.py", '--stage', '2', '-y')
if ($Extra) { $argv += $Extra }

Write-Host "== scripts/install-deps-windows.ps1 -> python $($argv -join ' ')"
& python @argv
exit $LASTEXITCODE
