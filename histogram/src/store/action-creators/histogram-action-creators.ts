import { HistogramActionType } from "../action-types/histogram-action-types";

export const GetRequestHistogram = () => ({
    type: HistogramActionType.REQUEST
});
export const GetSuccessHistogram = (data) => {
    return {
        type: HistogramActionType.SUCCESS,
        data: data
    };
};
export const GetFailureHistogram = (err) => ({
    type: HistogramActionType.FAILURE,
    error: err
});

export const GetHistogram = options => async dispatch => {
    // Notify our state that we're doing something asynchronous.     
    dispatch(GetRequestHistogram());
    // Sanity, don't need to pass the socket itself down the wire.
    const { socket } = options;
    delete options.socket;
    try {
        // Emit the request to the back-end via the socket.
        socket.emit(HistogramActionType.REQUEST, options);
    } catch (err) {
        dispatch(GetFailureHistogram(err));
    }
};