import { HistogramActionType as ActionType } from '../action-types/histogram-action-types'
import { HistogramDecrement, HistogramIncrement, HistogramReset } from '../actions/histogram';

const actionCreators = {
    increment: () => ({ type: ActionType.INCREMENT } as HistogramIncrement),
    decrement: () => ({ type: ActionType.DECREMENT } as HistogramDecrement),
    reset: () => ({ type: ActionType.RESET } as HistogramReset)
};

export default actionCreators;