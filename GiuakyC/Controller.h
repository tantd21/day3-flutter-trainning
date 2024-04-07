#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "BangHoaDon.h"

void readData(std::vector<BangHoaDon>& hoadons);
void showAllhoadons(const std::vector<BangHoaDon>& hoadons);
void addNewhoadon(std::vector<BangHoaDon>& hoadons);
void modifyhoadon(std::vector<BangHoaDon>& hoadons);
void deletehoadon(std::vector<BangHoaDon>& hoadons);
#endif  