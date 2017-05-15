library(ggplot2)
pdf("enqueue_comparacao.pdf")
data1 <- read.csv("../pq_enqueue.csv",header=T, sep=",", col.names=c("Comparacoes", "Elementos"))
qplot(data1$Elementos,data1$Comparacoes,colour = I("gray"),xlim=c(0,25000),size = I(1),xlab = "Elementos", ylab = "Comparações", main = "Enqueue - Priority Queue") + theme_minimal() + stat_function(fun=function(x)(x), aes(colour="y = n"), size = I(1.3)) +theme(legend.title=element_blank())

data2 <- read.csv("../heap_enqueue.csv",header=T, sep=",", col.names=c("Comparacoes", "Elementos"))
qplot(data2$Elementos,data2$Comparacoes,colour = I("gray"),xlim=c(0,25000),size = I(1),xlab = "Elementos", ylab = "Comparações", main = "Enqueue - Heap") + theme_minimal() + stat_function(fun=function(x)log2(x), aes(colour="y = lg(n)"), size = I(1.3)) +theme(legend.title=element_blank())
dev.off()