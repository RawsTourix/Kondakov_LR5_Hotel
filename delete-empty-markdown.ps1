# Запуск через терминал из директории проекта

# Удаление пустых директорий и файлов в .\docs\markdown\

$directoriesToDelete = @(
    ".\docs\markdown\Examples",
    ".\docs\markdown\images",
    ".\docs\markdown\Pages"
)

$filesToDelete = @(
    ".\docs\markdown\index_examples.md",
    ".\docs\markdown\index_pages.md"
)

foreach ($dir in $directoriesToDelete) {
    if (Test-Path $dir) {
        Remove-Item -Path $dir -Recurse -Force
        Write-Host "Директория $dir удалена."
    } else {
        Write-Host "Директория $dir не найдена."
    }
}

foreach ($file in $filesToDelete) {
    if (Test-Path $file) {
        Remove-Item -Path $file -Force
        Write-Host "Файл $file удалён."
    } else {
        Write-Host "Файл $file не найден."
    }
}