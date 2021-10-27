import * as React from 'react';
import { Jumbotron } from 'reactstrap';
import { Props } from './props';
import Histogram from '../../components/histogram';

export class Home extends React.PureComponent<Props> {
    public render() {
        return (
            <React.Fragment>
                <Jumbotron>
                    <Histogram/>
                </Jumbotron>
            </React.Fragment>
        );
    }
}