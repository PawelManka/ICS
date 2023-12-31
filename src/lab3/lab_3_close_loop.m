%% Train NARX Network and Predict on New Data
clear all
load("..\..\doc\lab_3\narxnet_workspace.mat")
%%
% Partition the training data. Use |Xnew| to do prediction in closed
% loop mode later.
x_begin_sample = 702;
x_end_sample = 4801;

Theta = dane_NN_test2.signals(1).values;
X = Theta(x_begin_sample:x_end_sample)';
X = num2cell(X);

X_train = X(1:3000);
Xnew = X(1000:2050);
Xnew = X(3000:4050);



%%
% Train a network, and simulate it on the first 80 observations
net = narxnet(1:2,1:2,1);
[Xs,Xi,Ai,Ts] = preparets(net,X_train,{},X_train);

net.divideFcn = 'dividetrain';
net.trainFcn = 'trainbr';

net = train(net,Xs,Ts,Xi,Ai);
view(net)

%%
% Calculate the network performance.
[Y,Xf,Af] = net(Xs,Xi,Ai);
perf = perform(net,Ts,Y)
Y_num = cell2mat(Y)

figure(11);
plot(Y_num)
hold on
plot(cell2mat(X_train))
legend('Open_loop', 'Train data')
hold off

figure(12); plot(Y_num - cell2mat(X_train(3:end)))



%%
% Run the prediction for 20 time steps ahead in closed loop mode.
[netc,Xic,Aic] = closeloop(net,Xf,Af);
view(netc)

%%
y2 = netc(Xnew,Xic,Aic)
yc_num = cell2mat(y2)
figure
plot(yc_num)
hold on 
plot(cell2mat(Xnew))
legend('Close loop', 'Train new')
figure(12); plot(yc_num - cell2mat(Xnew(3:end)))
