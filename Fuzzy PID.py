from pyb import millis
from math import  isnan

class FPID:
        _kp = _ki = _kd = _dkp = _dkd = _integrator = _imax = 0
        _last_t = _last_error = _last_derivative = 0
        _RC = 1 / (2 * pi * 20)

        def __init__(self, _kp = 0, _ki = 0, _kd = 0, _imax = 0):
                self._kp = float(_kp)
                self._ki = float(_ki)
                self._kd = float(_kd)
                self._imax = _imax
                self._last_derivative = float("nan")

        def Get_PID(self):
                self._dkp = 0
                self._dkd = 0


        def Get_Out(self, error):
                tnow = millis()
                dt = tnow - self._last_t
                output += self._kp*error
                if self._last_t == 0 and dt > 1000:
                        dt = 0
                        Reset_PID()

                dts = float(dt) / float(1000)
                self._last_t = tnow

                output += self._kd*(error - self._last_error) / dts

                self._integrator += error*dt
                output += self._ki * self._integrator

                return output

        def Reset_PID(self):
                self._integrator = 0
