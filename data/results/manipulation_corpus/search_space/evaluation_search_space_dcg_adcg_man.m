% program to plot the search space statistics from the h2sl::search_space_corpus_analysis program

clear all;

dcg_ss_concrete_size = [302; 302; 302; 302; 302; 302; 302; 302; 302; 302; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 150; 150; 150; 150; 174; 174; 222; 174; 222; 174; 174; 222; 174; 174; 222; 222; 174; 222; 222; 222; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 222; 222; 174; 174; 174; 174; 174; 174; 222; 222; 222; 174; 174; 222; 222; 222; 222; 222; 222; 222; 222; 222; 174; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 174; 174; 222; 174; 174; 222; 174; 174; 222; 222; 222; 174; 222; 222; 222; 174; 222; 174; 174; 222; 222; 174; 222; 222; 222; 222; 222; 222; 222];
dcg_ss_abstract_avg_size = [38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 2744; 2744; 2744; 2744; 3284; 3284; 6668; 3284; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 6668; 3284; 6668; 6668; 6668; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 6668; 6668; 3284; 3284; 3284; 3284; 3284; 3284; 6668; 6668; 6668; 3284; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 6668; 6668; 3284; 6668; 6668; 6668; 3284; 6668; 3284; 3284; 6668; 6668; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668];
dcg_ss_abstract_max_size = [38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 38820; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 149300; 2744; 2744; 2744; 2744; 3284; 3284; 6668; 3284; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 6668; 3284; 6668; 6668; 6668; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 3284; 6668; 6668; 3284; 3284; 3284; 3284; 3284; 3284; 6668; 6668; 6668; 3284; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 3284; 3284; 6668; 6668; 6668; 3284; 6668; 6668; 6668; 3284; 6668; 3284; 3284; 6668; 6668; 3284; 6668; 6668; 6668; 6668; 6668; 6668; 6668];
baseline = dcg_ss_concrete_size + dcg_ss_abstract_avg_size;


adcg_ss_concrete_size = [302; 302; 302; 302; 302; 302; 302; 302; 302; 302; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 342; 150; 150; 150; 150; 174; 174; 222; 174; 222; 174; 174; 222; 174; 174; 222; 222; 174; 222; 222; 222; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 174; 222; 222; 174; 174; 174; 174; 174; 174; 222; 222; 222; 174; 174; 222; 222; 222; 222; 222; 222; 222; 222; 222; 174; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 222; 174; 174; 222; 174; 174; 222; 174; 174; 222; 222; 222; 174; 222; 222; 222; 174; 222; 174; 174; 222; 222; 174; 222; 222; 222; 222; 222; 222; 222];
adcg_ss_abstract_avg_size = [305.2; 435; 1268; 305.2; 760.8; 435; 435; 759.8; 1268; 760.8; 1907; 629.5; 511.7; 3064; 1.5; 1.25; 767.4; 1277; 1788; 1788; 1788; 817.9; 817.9; 1.5; 1.5; 1.5; 1.444; 1.615; 1.615; 1.667; 1.667; 1.533; 2.714; 1.615; 25.33; 6.533; 1.533; 25.33; 1.533; 7.385; 25.6; 37; 25.6; 6.467; 1.467; 1.533; 6.533; 1.538; 1.533; 1.615; 6.467; 1.533; 6.533; 1.533; 1.615; 1.615; 1.538; 1.533; 1.533; 1.923; 1.533; 1.533; 2; 1.533; 1.615; 6.533; 1.615; 1.615; 1.467; 1.533; 1.533; 7.385; 1.533; 2.556; 1.533; 2.556; 1.533; 1.533; 2.556; 1.533; 1.533; 1.533; 2.714; 2.556; 2.556; 1.533; 2.556; 1.467; 1.533; 2.714; 1.533; 25.33; 1.533; 1.533; 1.533; 1.533; 1.533; 2.556; 1.533; 2.556; 2.556; 1.533; 1.533; 1.533; 1.533; 2.556; 2.714; 2.556; 1.533; 1.533; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 25.33; 1.533; 1.533; 1.533; 2.556; 2; 2.286; 1.615; 2; 2.714; 1.615; 2; 29.08];
adcg_ss_abstract_max_size = [305.2; 435; 1268; 305.2; 760.8; 435; 435; 759.8; 1268; 760.8; 1907; 629.5; 511.7; 3064; 1.5; 1.25; 767.4; 1277; 1788; 1788; 1788; 817.9; 817.9; 1.5; 1.5; 1.5; 1.444; 1.615; 1.615; 1.667; 1.667; 1.533; 2.714; 1.615; 25.33; 6.533; 1.533; 25.33; 1.533; 7.385; 25.6; 37; 25.6; 6.467; 1.467; 1.533; 6.533; 1.538; 1.533; 1.615; 6.467; 1.533; 6.533; 1.533; 1.615; 1.615; 1.538; 1.533; 1.533; 1.923; 1.533; 1.533; 2; 1.533; 1.615; 6.533; 1.615; 1.615; 1.467; 1.533; 1.533; 7.385; 1.533; 2.556; 1.533; 2.556; 1.533; 1.533; 2.556; 1.533; 1.533; 1.533; 2.714; 2.556; 2.556; 1.533; 2.556; 1.467; 1.533; 2.714; 1.533; 25.33; 1.533; 1.533; 1.533; 1.533; 1.533; 2.556; 1.533; 2.556; 2.556; 1.533; 1.533; 1.533; 1.533; 2.556; 2.714; 2.556; 1.533; 1.533; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 2.556; 25.33; 1.533; 1.533; 1.533; 2.556; 2; 2.286; 1.615; 2; 2.714; 1.615; 2; 29.08];
adcg_adaptive_avg = adcg_ss_concrete_size + adcg_ss_abstract_avg_size;
adcg_adaptive_max = adcg_ss_concrete_size + adcg_ss_abstract_max_size;


figure(1);
hold on;
box on;
grid on;
scatter(baseline,baseline,200);
scatter(baseline,adcg_adaptive_avg,200,'+');
scatter(baseline,adcg_adaptive_max,200,'^');
legend('DCG','ADCG avg', 'ADCG max','Location','NorthWest');
title('Search space comparison');
xlhand = get(gca,'xlabel');
set(xlhand,'string','Total search space size','fontsize',15);
ylhand = get(gca,'ylabel');
set(ylhand,'string','Instantiated search space size','fontsize',15);
set(gcf, 'PaperPosition', [0 0 6 6]);
set(gcf, 'PaperSize', [6 6]);


saveas(gcf, 'search_space_comparison', 'epsc');

saveas(gcf, 'search_space_comparison', 'pdf');
