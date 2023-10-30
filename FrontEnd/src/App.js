import React from 'react';
import './App.css';
import TopBar from './components/Topbar';
import Navbar from './components/Navbar';
import PlantList from './components/PlantList';
function App() {
  return (
    <div>
      <TopBar />
      <div className="content">
        <Navbar />
        <PlantList />
        {/* Your main content goes here */}
      </div>
    </div>
  );
}

export default App;
