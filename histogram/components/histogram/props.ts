import { Histogram } from "../../store/states/histogram";
import * as HistogramActions from "../../store/action-creators/histogram-action-creators";

export type Props =
  Histogram
  & typeof HistogramActions.default
  & Properties


interface Properties{

}