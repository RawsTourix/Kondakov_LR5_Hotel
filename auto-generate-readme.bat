@echo off
chcp 65001
setlocal enabledelayedexpansion

:: Цвета: зелёный = A, красный = C, сброс = 7
set SUCCESS_COLOR=0A
set ERROR_COLOR=0C
set RESET_COLOR=07

echo Автоматическое создание markdown на основе XML, сгенерированного Doxygen
powershell -NoProfile -ExecutionPolicy Bypass -File "generate-markdown.ps1"
if %ERRORLEVEL% NEQ 0 (
    call :error "Ошибка при выполнении generate-markdown.ps1"
    goto end
)

echo Удаление пустых директорий и файлов в .\docs\markdown
powershell -NoProfile -ExecutionPolicy Bypass -File "delete-empty-markdown.ps1"
if %ERRORLEVEL% NEQ 0 (
    call :error "Ошибка при выполнении delete-empty-markdown.ps1"
    goto end
)

echo Генерация README.md
powershell -NoProfile -ExecutionPolicy Bypass -File "generate-readme-refs.ps1"
if %ERRORLEVEL% NEQ 0 (
    call :error "Ошибка при выполнении generate-readme-refs.ps1"
    goto end
)

:: Успешное завершение
call :success "README.md успешно сгенерирован!"

:end
pause
exit /b

:success
color %SUCCESS_COLOR%
echo %~1
color %RESET_COLOR%
goto :eof

:error
color %ERROR_COLOR%
echo %~1
color %RESET_COLOR%
goto :eof