clear all
close all
clc

load sensor9pts
load sensor24pts
load sensor161pts


figure(1);
plot(SensorData24p.Distance_mm, SensorData24p.Sensor_V, 'kd');
hold on;
plot(SensorData9p.Distance_mm, SensorData9p.Sensor_V, 'b*');
plot(SensorData161p.Distance_mm, SensorData161p.Sensor_V, 'r.');
hold off
grid on;
xlabel('Distance (mm)');
ylabel('Voltage (V)');

y = SensorData9p.Distance_mm;
x = SensorData9p.Sensor_V;
