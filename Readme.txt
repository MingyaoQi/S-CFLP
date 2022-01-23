##############################INSTANCE FILES ############################## 
All instance files are named as instance_I_J.csv where I is the number of customer points and J is the number of candidate facility sites. Please note that no existing facility is considered in these instances.

Format of the instant files:
I	J
x1_1	y1_1
x1_2	y1_2
...
x1_I	y1_I
x2_1	y2_1
x2_2	y2_2
...
x2_J	y2_J

where (x1,y1) is for customer points and (x2, y2）is for candidate facility sites. Note also that \beta is set to 0.1 and \alpha_i is set to 0.0 (for the MNL model) for all instances ecxept for the sensitivity analysis.

To generate new instance files, one can use the function GenerateInstance(int num_rows_columns, int I, int J) defined in data.cpp. Calling this function will create an instance file with the aforementioned naming rules. Here num_rows_columns is the maximum horizontal (and vertical) coordinates of the facilities and customers.

