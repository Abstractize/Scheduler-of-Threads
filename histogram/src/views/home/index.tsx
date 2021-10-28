import * as React from 'react';
import { Jumbotron } from 'reactstrap';
import { Props } from './props';
import Histogram from '../../components/histogram'

export class Home extends React.PureComponent<Props> {
    public render() {
        return (
            <React.Fragment>
                <div style={{padding: "5%", backgroundColor: "#282c34", color: "white"}}>
                <h1>Vowel Histogram</h1>
                    <Jumbotron className="App-header">
                        <Histogram />
                    </Jumbotron>
                </div>
            </React.Fragment>
        );
    }
}