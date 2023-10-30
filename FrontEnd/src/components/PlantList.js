// PlantList.js
import React, { useState } from 'react';
import PlantStatus from './PlantStatus';

function PlantList() {
  const [plants, setPlants] = useState([]);
  const [newPlantName, setNewPlantName] = useState('');
  const [newPlantLocation, setNewPlantLocation] = useState('');
  const [newPlantStatus, setNewPlantStatus] = useState('');

  const addPlant = () => {
    if (newPlantName && newPlantStatus) {
      const newPlant = {
        name: newPlantName,
        location: newPlantLocation,
        status: newPlantStatus,
      };
      setPlants([...plants, newPlant]);
      setNewPlantName('');
      setNewPlantLocation('');
      setNewPlantStatus('');
    }
  };

  return (
    <div>
      <div className="add-plant">
        <input
          type="text"
          placeholder="Plant Name"
          value={newPlantName}
          onChange={(e) => setNewPlantName(e.target.value)}
        />
         <input
          type="text"
          placeholder="Location"
          value={newPlantLocation}
          onChange={(e) => setNewPlantLocation(e.target.value)}
        />
        <input
          type="text"
          placeholder="Status"
          value={newPlantStatus}
          onChange={(e) => setNewPlantStatus(e.target.value)}
        />
        <button onClick={addPlant}>Add Plant</button>
      </div>
      <div className="plant-list">
        {plants.map((plant, index) => (
          <PlantStatus key={index} plant={plant} />
        ))}
      </div>
    </div>
  );
}

export default PlantList;
