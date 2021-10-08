#include "../models/histrogram.c"

/**
 * @brief Adds Histogram to the List and returns it's id
 * 
 * @param histogram 
 * @return int 
 */
int add(histogram_t histogram);
/**
 * @brief Find Histogram with the given id
 * 
 * @param id 
 * @return histogram_t 
 */
histogram_t find(int id);
/**
 * @brief Updates Histogram with the given id
 * 
 * @param id 
 * @param histrogram 
 */
void update(int id, histogram_t histrogram);
