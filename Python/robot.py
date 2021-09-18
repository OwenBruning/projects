import constants as c
import random
import matplotlib.pyplot as plt
import pyrosim
import numpy

sim = pyrosim.Simulator( play_paused = False, eval_time=1000 )

class ROBOT:

  def send_objects(self,sim):
    whiteObject = sim.send_cylinder( x=0 , y=0 , z=0.6 , length=1.0 , radius=0.1 )
    redObject = sim.send_cylinder( x=0 , y=0.5 , z=1.1, r1=0, r2=1, r3=0, r=1, g=0, b=0 )

  def send_joints(self,sim):
    joint = sim.send_hinge_joint( first_body_id = whiteObject , second_body_id = redObject, x=0, y=0, z=1.1, n1 = -1 , n2 = 0 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )

  def send_sensors(self,sim):
    T0 = sim.send_touch_sensor( body_id = whiteObject )
    self.P4 = sim.send_position_sensor( body_id = redObject )
    T1 = sim.send_touch_sensor( body_id = redObject )
    P2 = sim.send_proprioceptive_sensor( joint_id = joint )
    R3 = sim.send_ray_sensor( body_id = redObject , x = 0 , y = 1.1 , z = 1.1 , r1 = 0 , r2 = 1, r3 = 0)

  def send_neurons(self,sim):
    MN2 = sim.send_motor_neuron( joint_id = joint )
    SN0 = sim.send_sensor_neuron( sensor_id = T0 )
    SN1 = sim.send_sensor_neuron( sensor_id = T1 )
    SN2 = sim.send_sensor_neuron( sensor_id = P2 )
    SN3 = sim.send_sensor_neuron( sensor_id = R3 )
    motorNeurons = {}
    motorNeurons[0] = MN2
    sensorNeurons = {}
    sensorNeurons[0] = SN0
    sensorNeurons[1] = SN1
    sensorNeurons[2] = SN2
    sensorNeurons[3] = SN3

  def send_synapses(self,sim,wts):
    for s in sensorNeurons:
      for m in motorNeurons:
        sim.send_synapse( source_neuron_id = sensorNeurons[s] , target_neuron_id = motorNeurons[m] , weight = wts[s] )

  def __init__(self,sim,wts):
    sim = pyrosim.Simulator( play_paused = False, eval_time=300 )
    robot = ROBOT( sim , self.genome )
    whiteObject = sim.send_cylinder( x=0 , y=0 , z=0.6 , length=1.0 , radius=0.1 )
    redObject = sim.send_cylinder( x=0 , y=0.5 , z=1.1, r1=0, r2=1, r3=0, r=1, g=0, b=0 )
    O0 = sim.send_box(x=0, y=0, z=c.L + c.R, length=c.L, width=c.L, height=2*(c.R), r=0.5, g=0.5, b=0.5)
    O1 = sim.send_cylinder(x=0, y=c.L, z=c.L + c.R, length=c.L, radius=c.R, r1=0, r2=1, r3=0, r=0.9, g=0, b=0)
    O2 = sim.send_cylinder(x=c.L, y=0, z=c.L + c.R, length=c.L, radius=c.R, r1=1, r2=0, r3=0, r=0, g=0.9, b=0)
    O3 = sim.send_cylinder(x=0, y=-c.L, z=c.L + c.R, length=c.L, radius=c.R, r1=0, r2=-1, r3=0, r=0, g=0, b=0.9)
    O4 = sim.send_cylinder(x=-c.L, y=0, z=c.L + c.R, length=c.L, radius=c.R, r1=-1, r2=0, r3=0, r=0.9, g=0, b=0.4)
    O5 = sim.send_cylinder(x=0, y=c.L*3/2, z=c.L/2+c.R, length=c.L, radius=c.R, r=0.8, g=0, b=0)
    O6 = sim.send_cylinder(x=c.L*3/2, y=0, z=c.L/2+c.R, length=c.L, radius=c.R, r=0, g=0.8, b=0)
    O7 = sim.send_cylinder(x=0, y=-(c.L*3/2), z=c.L/2+c.R, length=c.L, radius=c.R, r=0, g=0, b=0.8)
    O8 = sim.send_cylinder(x=-(c.L*3/2), y=0, z=c.L/2+c.R, length=c.L, radius=c.R, r=0.9, g=0, b=0.3)

    joint = sim.send_hinge_joint( first_body_id = whiteObject , second_body_id = redObject, x=0, y=0, z=1.1, n1 = -1 , n2 = 0 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    J0 = sim.send_hinge_joint( first_body_id = O0 , second_body_id = O1, x=0, y=c.L/2, z=c.L+c.R, n1 = -1 , n2 = 0 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    J1 = sim.send_hinge_joint( first_body_id = O1 , second_body_id = O5, x=0, y=c.L/2*3, z=c.L+c.R, n1 = -1 , n2 = 0 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    J2 = sim.send_hinge_joint( first_body_id = O0 , second_body_id = O2, x=c.L/2, y=0, z=c.L+c.R, n1 = 0 , n2 = 1 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    J3 = sim.send_hinge_joint( first_body_id = O2 , second_body_id = O6, x=c.L/2*3, y=0, z=c.L+c.R, n1 = 0 , n2 = 1 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    J4 = sim.send_hinge_joint( first_body_id = O0 , second_body_id = O3, x=0, y=-c.L/2, z=c.L+c.R, n1 = 1 , n2 = 0 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    J5 = sim.send_hinge_joint( first_body_id = O3 , second_body_id = O7, x=0, y=-c.L/2*3, z=c.L+c.R, n1 = 1 , n2 = 0 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    J6 = sim.send_hinge_joint( first_body_id = O0 , second_body_id = O4, x=-c.L/2, y=0, z=c.L+c.R, n1 = 0 , n2 = -1 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    J7 = sim.send_hinge_joint( first_body_id = O4 , second_body_id = O8, x=-c.L/2*3, y=0, z=c.L+c.R, n1 = 0 , n2 = -1 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )

    MN2 = sim.send_motor_neuron( joint_id = joint )
    motorNeurons = {}
    motorNeurons[0] = MN2

    T0 = sim.send_touch_sensor( body_id = O5 )
    T1 = sim.send_touch_sensor( body_id = O6 )
    T2 = sim.send_touch_sensor( body_id = O7 )
    T3 = sim.send_touch_sensor( body_id = O8 )
    self.P4 = sim.send_position_sensor( body_id = O0 )

    self.O = {}
    self.O[0] = O0
    self.O[1] = O1
    self.O[2] = O2
    self.O[3] = O3
    self.O[4] = O4
    self.O[5] = O5
    self.O[6] = O6
    self.O[7] = O7
    self.O[8] = O8

    self.J = {}
    self.J[0] = J0
    self.J[1] = J1
    self.J[2] = J2
    self.J[3] = J3
    self.J[4] = J4
    self.J[5] = J5
    self.J[6] = J6
    self.J[7] = J7

    self.S = {}
    self.S[0] = T0
    self.S[1] = T1
    self.S[2] = T2
    self.S[3] = T3

    self.SN = {}
    for s in self.S:
      self.SN[s] = sim.send_sensor_neuron(sensor_id = self.S[s])

    self.MN = {}
    for j in self.J:
      self.MN[j] = sim.send_motor_neuron(joint_id = self.J[j], tau = 0.3)

    for sn in self.SN:
      firstMN = min( self.MN , key=self.MN.get )
      sim.send_synapse(source_neuron_id = self.SN[sn] , target_neuron_id = self.MN[firstMN] , weight = random.random()*2 - 1 )

    for j in self.SN:
      for i in self.MN:
        sim.send_synapse(source_neuron_id = self.SN[j], target_neuron_id = self.MN[i], weight = wts[j,i] )

    del self.O
    del self.J
    del self.S
    del self.SN
    del self.MN

    self.P4 = sim.send_position_sensor( body_id = redObject )
    T1 = sim.send_touch_sensor( body_id = redObject )
    P2 = sim.send_proprioceptive_sensor( joint_id = joint )
    R3 = sim.send_ray_sensor( body_id = redObject , x = 0 , y = 1.1 , z = 1.1 , r1 = 0 , r2 = 1, r3 = 0)

    SN0 = sim.send_sensor_neuron( sensor_id = T0 )
    SN1 = sim.send_sensor_neuron( sensor_id = T1 )
    SN2 = sim.send_sensor_neuron( sensor_id = P2 )
    SN3 = sim.send_sensor_neuron( sensor_id = R3 )
    sensorNeurons = {}
    sensorNeurons[0] = SN0
    sensorNeurons[1] = SN1
    sensorNeurons[2] = SN2
    sensorNeurons[3] = SN3
    for s in sensorNeurons:
      for m in motorNeurons:
        sim.send_synapse( source_neuron_id = sensorNeurons[s] , target_neuron_id = motorNeurons[m] , weight = wts[s] )
    self.send_objects(self)
    self.send_joints(self)
    self.send_sensors(self)
    self.send_neurons(self)
    self.send_synapses(self,wts)

    sim.start()
    sim.wait_to_finish()
    whiteObject = sim.send_cylinder( x=0 , y=0 , z=0.6 , length=1.0 , radius=0.1 )
    redObject = sim.send_cylinder( x=0 , y=0.5 , z=1.1, r1=0, r2=1, r3=0, r=1, g=0, b=0 )
    joint = sim.send_hinge_joint( first_body_id = whiteObject , second_body_id = redObject, x=0, y=0, z=1.1, n1 = -1 , n2 = 0 , n3 = 0, lo=-3.14159/2 , hi=3.14159/2 )
    MN2 = sim.send_motor_neuron( joint_id = joint )
    joint = sim.send_hinge_joint( first_body_id = whiteObject , second_body_id = redObject, x=0, y=0, z=1.1, n1 = 0 , n2 = -1 , n3 = 0 )
    T1 = sim.send_touch_sensor( body_id = redObject )
    P2 = sim.send_proprioceptive_sensor( joint_id = joint )
    R3 = sim.send_ray_sensor( body_id = redObject , x = 0 , y = 1.1 , z = 1.1 , r1 = 0 , r2 = 1, r3 = 0)
    T0 = sim.send_touch_sensor( body_id = whiteObject )
    self.P4 = sim.send_position_sensor( body_id = redObject )
    SN0 = sim.send_sensor_neuron( sensor_id = T0 )
    SN1 = sim.send_sensor_neuron( sensor_id = T1 )
    sim.send_synapse(source_neuron_id = SN0 , target_neuron_id = MN2 , weight = -1.0 )
    sim.send_synapse(source_neuron_id = SN1 , target_neuron_id = MN2 , weight = wts[s])

sim.start()
sim.wait_to_finish()
sensorData = sim.get_sensor_data( sensor_id = R3 )
sensorData = sim.get_sensor_data( sensor_id = P2 )
print(sensorData)
f = plt.figure()
panel = f.add_subplot(111)
plt.plot(sensorData)
panel.set_ylim(-2,+2)
plt.show()
