import matplotlib.pyplot as plt
import pandas as pd


#set directory
df=pd.read_excel('graphdata.xlsx','Sheet1')
#set plot
plt.plot(df['Time'],df['Process'])


#set label
plt.xlabel('Type of process')
plt.ylabel('Time in seconds')
plt.title('Time differentiation of using OpenMP')


plt.show()
