<h2>Project Description</h2>
<p>
  This project demonstrates the performance difference between using 
  <strong>1 thread</strong> and <strong>multiple threads</strong> in matrix multiplication.
</p>

<h2>What This Project Tests</h2>
<ul>
  <li>Speed of single-thread execution</li>
  <li>Speed of multi-thread execution</li>
  <li>Comparison using different parallel programming libraries</li>
</ul>

<h2>How to Compile</h2>
<pre>
gcc -o main.out Matrix_Multiplication.c
</pre>

<h2>Setting the Number of Threads</h2>

<h3>Windows (PowerShell)</h3>
<pre>
$env:OMP_NUM_THREADS = &lt;number&gt;
</pre>

<h3>Linux</h3>
<pre>
export OMP_NUM_THREADS=10
</pre>

<h2>How to Run</h2>
<pre>
./main.out
</pre>
