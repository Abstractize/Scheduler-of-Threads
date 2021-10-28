import { HistogramActionType } from "../../store/action-types/histogram-action-types";
import { HistogramErrorAction, HistogramRecievedAction } from "../../store/actions/histogram";
import { Histogram } from "../models/histogram";

export class HistogramService {
    private socket: WebSocket;
    private urlpath: string = 'ws://localhost:5000/websocket';
    constructor(dispatch) {
        this.socket = new WebSocket(this.urlpath);

        this.socket.onmessage = (event) => {
            let response: Histogram = JSON.parse(event.data);
            console.log(response);
            dispatch({type: HistogramActionType.SUCCESS, data: response} as HistogramRecievedAction)
        }

        this.socket.onerror = (event) => {
            dispatch({type: HistogramActionType.FAILURE, error: event} as HistogramErrorAction)
        }
    }
}