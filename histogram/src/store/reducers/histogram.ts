import { Reducer } from 'redux'
import { HistogramActionType } from '../action-types/histogram-action-types'
import { Action } from '../actions'
import { Histogram } from '../states/histogram'

const initialState: Histogram = new Histogram();

const reducer: Reducer<Histogram, Action> = (
    state: Histogram | undefined,
    action: Action,
): Histogram => {
    if (state === undefined) return initialState
    switch (action.type) {
        case HistogramActionType.SUCCESS:
            return {
                ...state,
                data: action.data.results,
                isFetching: false
              };
        case HistogramActionType.REQUEST:
            return {
                ...state,
                isFetching: true,
                error: null
              };
        case HistogramActionType.FAILURE:
            return {
                ...state,
                error: action.error,
                isFetching: false
            }
        default:
            return state;
    }
}

export default reducer;