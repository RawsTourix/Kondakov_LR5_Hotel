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

## Detailed Description

Основной заголовочный файл проекта, содержащий подключения библиотек, объявления типов и вспомогательные макросы. 

**Author**: Kondakov Fedor 

**Version**: 1.0

**Date**: 2025 

**Copyright**: Copyright (c) 2025 Fedor Kondakov @license MIT 



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
 // Конец группы core_definitionsы

#endif // KONDAKOV_LR5_DEF_H
```


-------------------------------

Updated on 2025-05-09 at 18:16:45 +0300
