import random
while(True):
    a=random.randint(10,99)
    b=random.randint(10,99)
    if(a>35 and b>60):
        print("High temperature and humidity of:",a,"%",b,"% is sensed.","\n Alarm is on")
    elif(a<35 and b<60):
        print("Normal temperature and humidity of:",a,"%",b,"% is sensed","\n Alarm is off")
        break
