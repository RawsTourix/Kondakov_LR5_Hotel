/**
 * @file kondakov_lr5_def.h
 * @brief Основной заголовочный файл проекта, содержащий подключения библиотек,
 *        объявления типов и вспомогательные макросы.
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup core_definitions
 */

#ifndef KONDAKOV_LR5_DEF_H
 /// @brief Макрос защиты от повторного включения заголовочного файла
#define KONDAKOV_LR5_DEF_H

/**
 * @defgroup core_definitions Основные определения
 * @brief Группа основных определений и подключений библиотек
 * @{
 */

#include <iostream>      ///< Потоки ввода-вывода (std::cin, std::cout).
#include <utility>       ///< Утилиты: std::pair, std::move, std::forward.
#include <vector>        ///< Динамический массив (std::vector).
#include <map>           ///< Ассоциативный контейнер (std::map).
#include <sstream>       ///< Строковые потоки (std::stringstream).
#include <functional>    ///< Функциональные объекты (std::function).
#include <type_traits>   ///< Метапрограммирование (std::is_same, std::enable_if).
#include <memory>        ///< Умные указатели (std::shared_ptr, std::unique_ptr).
#include <algorithm>     ///< Алгоритмы (std::sort, std::find).
#include <limits>        ///< Пределы типов (std::numeric_limits).
#include <tuple>         ///< Кортежи (std::tuple).
#include <fstream>       ///< Файловые потоки (std::ifstream, std::ofstream).
#include <nlohmann/json.hpp> ///< JSON-библиотека (nlohmann::json).

 /// @brief Использование стандартного пространства имён (может приводить к конфликтам имен)
using namespace std;
/// @brief Псевдоним для удобства работы с JSON библиотекой
using json = nlohmann::json;

/** @} */ // end of core_definitions

#endif // KONDAKOV_LR5_DEF_H