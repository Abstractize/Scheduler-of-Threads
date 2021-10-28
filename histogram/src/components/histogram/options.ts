import { BarControllerChartOptions, CoreChartOptions, DatasetChartOptions, ElementChartOptions, PluginChartOptions, ScaleChartOptions } from "chart.js"
import { _DeepPartialObject } from "chart.js/types/utils"

export type Options = 
_DeepPartialObject<CoreChartOptions<"bar"> 
& ElementChartOptions<"bar"> 
& PluginChartOptions<"bar"> 
& DatasetChartOptions<"bar"> 
& ScaleChartOptions
& BarControllerChartOptions>