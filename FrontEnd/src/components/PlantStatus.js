// PlantStatus.js
import React from 'react';
import './PlantStatus.css';
import PropTypes from 'prop-types';

function PlantStatus({ plant }) {
  const { name, location, status } = plant;
  return (
    <div className="plant-status">
      <h3>{name}</h3>
      <p>Location: {location}</p>
      <p>Status: {status}</p>
    </div>
  );
}

PlantStatus.propTypes = {
  plant: PropTypes.shape({
    name: PropTypes.string.isRequired,
    location: PropTypes.string.isRequired,
    status: PropTypes.string.isRequired
  }).isRequired
};

export default PlantStatus;
