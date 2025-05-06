---
title: Kondakov_LR5_Hotel/kondakov_lr5_def.h
summary: Основной заголовочный файл проекта, содержащий подключения библиотек, объявления типов и вспомогательные макросы. 

---

# Kondakov_LR5_Hotel/kondakov_lr5_def.h

Основной заголовочный файл проекта, содержащий подключения библиотек, объявления типов и вспомогательные макросы.  [More...](#detailed-description)

## Namespaces

| Name           |
| -------------- |
| **[std](Namespaces/namespacestd.md)** <br>< JSON-библиотека (nlohmann::json).  |

## Defines

|                | Name           |
| -------------- | -------------- |
|  | **[KONDAKOV_LR5_DEF_H](Files/kondakov__lr5__def_8h.md#define-kondakov-lr5-def-h)** <br>Макрос защиты от повторного включения заголовочного файла  |

## Detailed Description

Основной заголовочный файл проекта, содержащий подключения библиотек, объявления типов и вспомогательные макросы. 

**Author**: Kondakov Fedor 

**Version**: 1.0 

**Date**: 2025 



## Macros Documentation

### define KONDAKOV_LR5_DEF_H

```cpp
#define KONDAKOV_LR5_DEF_H 
```

Макрос защиты от повторного включения заголовочного файла 

## Source code

```cpp


#ifndef KONDAKOV_LR5_DEF_H
#define KONDAKOV_LR5_DEF_H


#include <iostream>      
#include <utility>       
#include <vector>        
#include <map>           
#include <sstream>       
#include <functional>    
#include <type_traits>   
#include <memory>        
#include <algorithm>     
#include <limits>        
#include <tuple>         
#include <fstream>       
#include <nlohmann/json.hpp> 

using namespace std;
using json = nlohmann::json;
 // end of core_definitions

#endif // KONDAKOV_LR5_DEF_H
```


-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300
