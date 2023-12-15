L = 720;
input_vec = readmatrix("matlab_vector.txt");
t = linspace(0,L,L+1);
input_mat_M8 = [t; ones(1,L+1)*input_vec(1); ones(1,L+1)*input_vec(2); ones(1,L+1)*input_vec(3); ones(1,L+1)*input_vec(4); ones(1,L+1)*input_vec(5); ones(1,L+1)*input_vec(6); ones(1,L+1)*input_vec(7); ones(1,L+1)*input_vec(8); ones(1,L+1)*input_vec(9); ones(1,L+1)*input_vec(10); ones(1,L+1)*input_vec(11); ones(1,L+1)*input_vec(12); ones(1,L+1)*input_vec(13); ones(1,L+1)*input_vec(14); ones(1,L+1)*input_vec(15); ones(1,L+1)*input_vec(16); ones(1,L+1)*8.5];
input_mat_M7 = [t; ones(1,L+1)*input_vec(1); ones(1,L+1)*input_vec(2); ones(1,L+1)*input_vec(3); ones(1,L+1)*input_vec(4); ones(1,L+1)*input_vec(5); ones(1,L+1)*input_vec(6); ones(1,L+1)*input_vec(7); ones(1,L+1)*input_vec(8); ones(1,L+1)*input_vec(9); ones(1,L+1)*input_vec(10); ones(1,L+1)*input_vec(11); ones(1,L+1)*input_vec(12); ones(1,L+1)*input_vec(13); ones(1,L+1)*input_vec(14); ones(1,L+1)*input_vec(15); ones(1,L+1)*input_vec(16); ones(1,L+1)*7.5];
input_mat_M6 = [t; ones(1,L+1)*input_vec(1); ones(1,L+1)*input_vec(2); ones(1,L+1)*input_vec(3); ones(1,L+1)*input_vec(4); ones(1,L+1)*input_vec(5); ones(1,L+1)*input_vec(6); ones(1,L+1)*input_vec(7); ones(1,L+1)*input_vec(8); ones(1,L+1)*input_vec(9); ones(1,L+1)*input_vec(10); ones(1,L+1)*input_vec(11); ones(1,L+1)*input_vec(12); ones(1,L+1)*input_vec(13); ones(1,L+1)*input_vec(14); ones(1,L+1)*input_vec(15); ones(1,L+1)*input_vec(16); ones(1,L+1)*6.5];
input_mat_M5 = [t; ones(1,L+1)*input_vec(1); ones(1,L+1)*input_vec(2); ones(1,L+1)*input_vec(3); ones(1,L+1)*input_vec(4); ones(1,L+1)*input_vec(5); ones(1,L+1)*input_vec(6); ones(1,L+1)*input_vec(7); ones(1,L+1)*input_vec(8); ones(1,L+1)*input_vec(9); ones(1,L+1)*input_vec(10); ones(1,L+1)*input_vec(11); ones(1,L+1)*input_vec(12); ones(1,L+1)*input_vec(13); ones(1,L+1)*input_vec(14); ones(1,L+1)*input_vec(15); ones(1,L+1)*input_vec(16); ones(1,L+1)*5.5];
input_mat_M4 = [t; ones(1,L+1)*input_vec(1); ones(1,L+1)*input_vec(2); ones(1,L+1)*input_vec(3); ones(1,L+1)*input_vec(4); ones(1,L+1)*input_vec(5); ones(1,L+1)*input_vec(6); ones(1,L+1)*input_vec(7); ones(1,L+1)*input_vec(8); ones(1,L+1)*input_vec(9); ones(1,L+1)*input_vec(10); ones(1,L+1)*input_vec(11); ones(1,L+1)*input_vec(12); ones(1,L+1)*input_vec(13); ones(1,L+1)*input_vec(14); ones(1,L+1)*input_vec(15); ones(1,L+1)*input_vec(16); ones(1,L+1)*4.5];


save("input.mat", "input_mat_M8");
sim("Manuf30_MX.slx", L);
output_struct = load("output.mat");
output_mat = output_struct.ans;
writematrix(output_mat,"output_M8.txt");

save("input.mat", "input_mat_M7");
sim("Manuf30_MX.slx", L);
output_struct = load("output.mat");
output_mat = output_struct.ans;
writematrix(output_mat,"output_M7.txt");

save("input.mat", "input_mat_M6");
sim("Manuf30_MX.slx", L);
output_struct = load("output.mat");
output_mat = output_struct.ans;
writematrix(output_mat,"output_M6.txt");

save("input.mat", "input_mat_M5");
sim("Manuf30_MX.slx", L);
output_struct = load("output.mat");
output_mat = output_struct.ans;
writematrix(output_mat,"output_M5.txt");

save("input.mat", "input_mat_M4");
sim("Manuf30_MX.slx", L);
output_struct = load("output.mat");
output_mat = output_struct.ans;
writematrix(output_mat,"output_M4.txt");

exit;
exit;
