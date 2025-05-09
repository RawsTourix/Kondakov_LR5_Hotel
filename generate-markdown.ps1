# Запуск через терминал из дериктории проекта

# Папка markdown
$markdownOutput = ".\docs\markdown"

# Удаление папки, если существует (очистка)
if (Test-Path $markdownOutput) {
    Remove-Item $markdownOutput -Recurse -Force
}

# Создание папки, если не существует
if (-not (Test-Path $markdownOutput)) {
    New-Item -Path $markdownOutput -ItemType Directory | Out-Null
}

# Перегенерация
.\packages\doxybook2\bin\doxybook2.exe --input ".\docs\xml" --output $markdownOutput