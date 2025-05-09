/**
 * @file kondakov_lr5_def.h
 * @brief �������� ������������ ���� �������, ���������� ����������� ���������,
 *        ���������� ����� � ��������������� �������.
 * @author Kondakov Fedor
 * @date 2025
 * @version 1.0
 * @ingroup core_definitions
 * @copyright Copyright (c) 2025 Fedor Kondakov
 * @license MIT
 */

#ifndef KONDAKOV_LR5_DEF_H
#define KONDAKOV_LR5_DEF_H

/**
 * @defgroup core_definitions �������� �����������
 * @brief ������ �������� ����������� � ����������� ���������
 * @{
 */

#include <iostream>      ///< ������ �����-������ (std::cin, std::cout).
#include <utility>       ///< �������: std::pair, std::move.
#include <vector>        ///< ������������ ������ (std::vector).
#include <map>           ///< ������������� ��������� (std::map).
#include <sstream>       ///< ��������� ������ (std::stringstream).
#include <functional>    ///< �������������� ������� (std::function).
#include <type_traits>   ///< �������������������� (std::is_same, std::enable_if).
#include <memory>        ///< ����� ��������� (std::shared_ptr, std::unique_ptr).
#include <algorithm>     ///< ��������� (std::sort, std::find).
#include <limits>        ///< ������� ����� (std::numeric_limits).
#include <tuple>         ///< ������� (std::tuple).
#include <fstream>       ///< �������� ������ (std::ifstream, std::ofstream).
#include <nlohmann/json.hpp> ///< JSON-���������� (nlohmann::json).

/// ������������� ������������ ������������ ���
using namespace std;

/// ��������� ��� �������� ������ � JSON �����������
using json = nlohmann::json;

/** @} */ // ����� ������ core_definitions

#endif // KONDAKOV_LR5_DEF_H