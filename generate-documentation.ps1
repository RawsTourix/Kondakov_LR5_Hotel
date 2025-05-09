# Запуск через терминал из директории проекта

# Проверка наличия Doxygen в PATH
if (-not (Get-Command doxygen -ErrorAction SilentlyContinue)) {
    Write-Host "Doxygen не найден. Пожалуйста, установите его и убедитесь, что он добавлен в PATH." -ForegroundColor Red
    exit 1
}

# Проверка наличия Doxyfile
$doxyfile = "Doxyfile"
if (-not (Test-Path $doxyfile)) { 
    Write-Host "Doxyfile не найден. Сгенерируйте его с помощью команды 'doxygen -g $doxyfile'" -ForegroundColor Red
    exit 1
}

# Запуск Doxygen с конфигурационным файлом
Write-Host "Запуск Doxygen с файлом $doxyfile..." -ForegroundColor Green
doxygen $doxyfile