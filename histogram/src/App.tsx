import React from 'react';
import './App.css';
import Histogram from './components/histogram';
import { Provider } from 'react-redux';
import store from './store';

const Store = store();
class App extends React.Component {
  render() {
    return (
      <Provider store={Store}>
        <Histogram/>
      </Provider>
    )
  }
}

export default App;
