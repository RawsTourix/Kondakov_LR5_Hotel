@echo off
chcp 65001
setlocal enabledelayedexpansion

:: Цвета: зелёный = A, красный = C, сброс = 7
set SUCCESS_COLOR=0A
set ERROR_COLOR=0C
set RESET_COLOR=07

echo Генерация документации с помощью Doxygen
powershell -NoProfile -ExecutionPolicy Bypass -File "generate-documentation.ps1"
if %ERRORLEVEL% NEQ 0 (
    call :error "Ошибка при выполнении generate-documentation.ps1"
    goto end
)

:: Успешное завершение
call :success "Документация успешно сгенерирована!"

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