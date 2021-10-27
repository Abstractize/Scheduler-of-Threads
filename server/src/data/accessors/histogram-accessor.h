#include "../../api/models/histogram.h"

#ifndef HISTOGRAM_ACCESSOR_HEADER_H
#define HISTOGRAM_ACCESSOR_HEADER_H

/**
 * @brief Adds Histogram to the List and returns it's id
 * 
 * @param histogram 
 * @return int 
 */
int add(histogram_t histogram);
/**
 * @brief Finds last Histogram data
 * 
 * @param id 
 * @return histogram_t 
 */
histogram_t find();
/**
 * @brief Updates Histogram with the given id
 * 
 * @param id 
 * @param histogram 
 */
void update(int id, histogram_t histogram);

#endif