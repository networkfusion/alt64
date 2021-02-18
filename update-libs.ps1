New-Item -ItemType Directory -Force -Path "$PSScriptRoot\temp\"

$ProgressPreference = 'SilentlyContinue'

$url = "https://n64tools.blob.core.windows.net/binaries/N64-tools/libdragon/develop/latest/libdragon-win64.zip"
$output = "$PSScriptRoot\temp\libdragon.zip"

Write-Host "Downloading libdragon-win64.zip...." -NoNewline
Invoke-RestMethod -ContentType "application/octet-stream" -Uri $url -OutFile $output
Write-Host "Done."
Expand-Archive -Force -Path $output -DestinationPath "$PSScriptRoot\toolchain\libdragon\"

$url = "https://n64tools.blob.core.windows.net/binaries/N64-tools/mips64-gcc-toolchain/master/latest/gcc-toolchain-mips64-win64.zip"
$output = "$PSScriptRoot\temp\gcc-toolchain-mips64.zip"

Write-Host "Downloading gcc-toolchain-mips64.zip...." -NoNewline
Invoke-RestMethod -ContentType "application/octet-stream" -Uri $url -OutFile $output
Write-Host "Done."
Expand-Archive -Force -Path $output -DestinationPath "$PSScriptRoot\toolchain\"

$url = "https://n64tools.blob.core.windows.net/binaries/N64-tools/libs/n64/latest/libmikmod.zip"
$output = "$PSScriptRoot\temp\libmikmod.zip"

Write-Host "Downloading libmikmod.zip...." -NoNewline
Invoke-RestMethod -ContentType "application/octet-stream" -Uri $url -OutFile $output
Write-Host "Done."
Expand-Archive -Path $output -DestinationPath "$PSScriptRoot"


$url = "https://n64tools.blob.core.windows.net/binaries/N64-tools/libs/n64/latest/libmad.zip"
$output = "$PSScriptRoot\temp\libmad.zip"

Write-Host "Downloading libmad.zip...." -NoNewline
Invoke-RestMethod -ContentType "application/octet-stream" -Uri $url -OutFile $output
Write-Host "Done."
Expand-Archive -Path $output -DestinationPath "$PSScriptRoot"


$url = "https://n64tools.blob.core.windows.net/binaries/N64-tools/libs/n64/latest/libyaml.zip"
$output = "$PSScriptRoot\temp\libyaml.zip"

Write-Host "Downloading libyaml.zip...." -NoNewline
Invoke-RestMethod -ContentType "application/octet-stream" -Uri $url -OutFile $output
Write-Host "Done."
Expand-Archive -Path $output -DestinationPath "$PSScriptRoot"


Remove-Item -LiteralPath "$PSScriptRoot\temp\" -Force -Recurse
