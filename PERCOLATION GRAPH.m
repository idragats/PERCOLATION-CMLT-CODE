clear; clc; clf;
myfile=importdata("Percolation.txt");

figure(1)
plot(myfile(:,1),myfile(:,2),'+-b')
xlabel("P")
ylabel("Iav")
grid on
figure(2)
plot(myfile(:,1),myfile(:,3),'+-r')
xlabel("P")
ylabel("Iav'")
grid on
figure (3)
plot(myfile(:,1),myfile(:,4),'+-g')
grid on
xlabel("P")
ylabel("Pmax")

max=0;
imax=0;

for i=1:length(myfile(:,3))
       if (myfile(i,3)>max)
           max=myfile(i,3);
            imax=i;
       end    
       
end   
  pc=myfile(imax,1);
  
  pmionpc=abs(myfile(5:imax-1,1)-pc);
  pmionpc2=abs(myfile(imax+1:13,2)-pc);
   pmionpc3=abs(myfile(5:imax-1,3)-pc);
  
figure(4)
plot(log10(pmionpc),log10(myfile(5:imax-1,2)),'+r')
hold on
p=polyfit(log10(pmionpc),log10(myfile(5:imax-1,2)),1);
f=polyval(p,log10(pmionpc));
plot(log10(pmionpc),f)
legend('data',['Linear Equation is:y=',num2str(p(1)),'*x + ','(',num2str(p(2)),')'],'Location','northeast');
xlabel("Log(|P-Pc|),P<Pc")
ylabel("Log(Iav)")
title(" ã")
  
figure(5)
plot(log10(pmionpc2),log10(myfile(imax+1:13,3)),'+r')
hold on
p2=polyfit(log10(pmionpc2),log10(myfile(imax+1:13,3)),1);
f2=polyval(p2,log10(pmionpc2));
plot(log10(pmionpc2),f2)
legend('data',['Linear Equation is:y=',num2str(p2(1)),'*x + ','(',num2str(p2(2)),')'],'Location','northeast');
xlabel("Log(|P-Pc|),P>Pc")
ylabel("Log(Iav')")
title(" ã'")  
  
figure(6)
plot(log10(pmionpc3),log10(myfile(5:imax-1,3)),'+r')
hold on
p3=polyfit(log10(pmionpc3),log10(myfile(5:imax-1,3)),1);
f3=polyval(p3,log10(pmionpc3));
plot(log10(pmionpc3),f3)
legend('data',['Linear Equation is:y=',num2str(p3(1)),'*x + ','(',num2str(p3(2)),')'],'Location','northwest');
xlabel("Log(|P-Pc|),P>Pc")
ylabel("Log (Petemity)")
title("Petemity â")  
    