// TopBar.js
import React from 'react';
import './Topbar.css'
function TopBar() {
  return (
    <div className="top-bar">
      <div className="logo">
        <img src="logo.png" alt="Website Logo" />
      </div>
      <div className="account">
        <button>Login</button>
      </div>
    </div>
  );
}

export default TopBar;
