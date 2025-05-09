# Запуск через терминал из директории проекта

# Путь к документации
$markdownRoot = "docs/markdown"
if (-not (Test-Path $markdownRoot)) {
    Write-Host "Директория $markdownRoot не найдена." -ForegroundColor Red
    exit 1
}

# Путь к создаваемому README.md
$readme = "README.md"
if (-not (Test-Path $readme)) {
    Write-Host "Файл $markdownRoot не найден." -ForegroundColor Red
    exit 1
}

# Путь к краткому описанию программы
$previewPath = "preview.md"
if (-not (Test-Path $previewPath)) {
    Write-Host "Файл $previewPath не найден." -ForegroundColor Red
    exit 1
}

# Путь к информации об авторах и лицензии
$authorsPath = "authors.md"
if (-not (Test-Path $authorsPath)) {
    Write-Host "Файл $authorsPath не найден." -ForegroundColor Red
    exit 1
}

# Создание заголовка
Write-Host "Сборка $readme..."
Set-Content -Path $readme -Value ('# Документация лабораторной работы №5: "Система управления гостиничными номерами и бронированием"' + "`n`n") -Encoding UTF8

# Вставка содержимого preview.md
$previewContent = Get-Content -Path $previewPath -Raw -Encoding UTF8
Add-Content -Path $readme -Value "`n$previewContent`n" -Encoding UTF8
Write-Host "Добавлено описание $previewPath" -ForegroundColor Green

# Добавление заголовка для оглавления
Add-Content -Path $readme -Value "## Оглавление" -Encoding UTF8

# Добавление ссылок на все index_*.md
$indexFiles = Get-ChildItem -Path $markdownRoot -Filter "index_*.md" | Sort-Object Name
foreach ($file in $indexFiles) {
    $relativePath = "$markdownRoot/$($file.Name)"
    if (Test-Path $relativePath) {
        Add-Content -Path $readme -Value ("- [$($file.BaseName)]($relativePath)`n") -Encoding UTF8
        Write-Host "$relativePath добавлен в $readme" -ForegroundColor Green
    }
    else {
        Write-Host "Файл $relativePath не найден." -ForegroundColor Red
        exit 1
    }
}

# Добавление ссылок на подпапки и их файлы
$subFolders = Get-ChildItem -Path $markdownRoot -Directory
foreach ($folder in $subFolders) {
    Add-Content -Path $readme -Value "`n## $($folder.Name)`n" -Encoding UTF8
    $mdFiles = Get-ChildItem -Path $folder.FullName -Filter "*.md"
    foreach ($md in $mdFiles) {
        $relativePath = "$markdownRoot/$($folder.Name)/$($md.Name)"
        if (Test-Path $relativePath) {
            Add-Content -Path $readme -Value ("- [$($md.BaseName)]($relativePath)`n") -Encoding UTF8
            Write-Host "$relativePath добавлен в $readme" -ForegroundColor Green
        }
        else {
            Write-Host "Файл $relativePath не найден." -ForegroundColor Red
            exit 1
        }
    }
}

# Вставка содержимого authors.md
$authorsContent = Get-Content -Path $authorsPath -Raw -Encoding UTF8
Add-Content -Path $readme -Value "`n$authorsContent`n" -Encoding UTF8
Write-Host "Добавлена информация об авторах и лицензии $authorsPath" -ForegroundColor Green