// PlantStatus.js
import React from 'react';
import './PlantStatus.css'
function PlantStatus({ plant }) {
  return (
    <div className="plant-status">
      <h3>{plant.name}</h3>
      <p>Location: {plant.location}</p>
      <p>Status: {plant.status}</p>
    </div>
  );
}

export default PlantStatus;
