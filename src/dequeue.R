library(ggplot2)
pdf("dequeue_comparacao.pdf")
data1 <- read.csv("../pq_dequeue.csv",header=T, sep=",", col.names=c("Comparacoes", "Elementos"))
qplot(data1$Elementos,data1$Comparacoes,colour = I("gray"),xlim=c(0,25000),size = I(1),xlab = "Elementos", ylab = "Comparações", main = "Dequeue - Priority Queue") + theme_minimal() + stat_function(fun=function(x)(1), aes(colour="y = 1"), size = I(1.3)) +theme(legend.title=element_blank())

data2 <- read.csv("../heap_dequeue.csv",header=T, sep=",", col.names=c("Comparacoes", "Elementos"))
qplot(data2$Elementos,data2$Comparacoes,colour = I("gray"),xlim=c(0,25000),size = I(1),xlab = "Elementos", ylab = "Comparações", main = "Dequeue - Heap") + theme_minimal() + stat_function(fun=function(x)(1), aes(colour="y = 1"), size = I(1.3)) +theme(legend.title=element_blank())
dev.off()