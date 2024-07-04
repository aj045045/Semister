package com.as.bsc.demos;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.widget.TextView;

import com.as.bsc.R;

public class SensorsActivity extends AppCompatActivity implements SensorEventListener {

    private SensorManager sensorManager;
    private Sensor accelerometerSensor;
    private Sensor proximitySensor;
    private Sensor ambTempSensor;

    private TextView tvAccValues, tvProxValues, tvAmbValues;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sensors);

        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        accelerometerSensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        proximitySensor = sensorManager.getDefaultSensor(Sensor.TYPE_PROXIMITY);
        ambTempSensor = sensorManager.getDefaultSensor(Sensor.TYPE_AMBIENT_TEMPERATURE);
        tvAccValues = findViewById(R.id.tvAccSensorData);
        tvProxValues = findViewById(R.id.tvProxSensorData);
        tvAmbValues = findViewById(R.id.tvAmbSensorData);

    }

    @Override
    protected void onResume() {
        super.onResume();
        sensorManager.registerListener(this, accelerometerSensor, SensorManager.SENSOR_DELAY_NORMAL);
        sensorManager.registerListener(this, proximitySensor, SensorManager.SENSOR_DELAY_NORMAL);
        sensorManager.registerListener(this, ambTempSensor, SensorManager.SENSOR_DELAY_NORMAL);
    }

    @Override
    protected void onPause() {
        super.onPause();
        sensorManager.unregisterListener(this);
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        if (event.sensor.getType() == accelerometerSensor.getType()) {
            String values = "Acc Sensor:     X: " + event.values[0] + "     Y:" + event.values[1] + "     Z:" + event.values[2];
            tvAccValues.setText(values);
        } else if (event.sensor.getType() == proximitySensor.getType()) {
            String values = "Proximity Sensor: " + event.values[0];
            tvProxValues.setText(values);
        } else if (event.sensor.getType() == ambTempSensor.getType()) {
            String values = "Amb Temp Sensor: " + event.values[0];
            tvAmbValues.setText(values);
        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
//
    }
}