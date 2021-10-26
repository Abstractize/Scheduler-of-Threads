import { Histogram } from "../../store/states/histogram";
import * as ActionCreators from "../../store/action-creators/histogram-action-creators"
import { Store } from "redux";

// At runtime, Redux will merge together...
export type Props =
  Histogram
  & typeof ActionCreators
  & {store: Store};