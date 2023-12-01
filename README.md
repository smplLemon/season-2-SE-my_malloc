# season-2-SE-my_malloc
<div class="card-block">
<div class="row">
<div class="col tab-content">
<div class="tab-pane active show" id="subject" role="tabpanel">
<div class="row">
<div class="col-md-12 col-xl-12">
<div class="markdown-body">
<p class="text-muted m-b-15">
</p><h1>My Malloc</h1>
<p>Remember to git add &amp;&amp; git commit &amp;&amp; git push each exercise!</p>
<p>We will execute your function with our test(s), please DO NOT PROVIDE ANY TEST(S) in your file</p>
<p>For each exercise, you will have to create a folder and in this folder, you will have additional files that contain your work. Folder names are provided at the beginning of each exercise under <code>submit directory</code> and specific file names for each exercise are also provided at the beginning of each exercise under <code>submit file(s)</code>.</p>
<hr>
<table>
<thead>
<tr>
<th>My Malloc</th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td>Submit directory</td>
<td>.</td>
</tr>
<tr>
<td>Submit files</td>
<td>Makefile - *.c - *.h</td>
</tr>
</tbody>
</table>
<h3>Description</h3>
<p>My_malloc is certainly one of the project you will learn the most in term of UNIX / Algorithm / Implementation.
It's an endless project, there is no <code>best</code> solution. Dive in with a plan in order to don't be stuck inside this project :-)</p>
<img src="https://storage.googleapis.com/qwasar-public/s02_SE/malloc_intro.png" width="400">
<p>Stack and Heap</p>
<p>Memory is one of main avantage of using C, it's also one of the main difficulty: You have to manage it yourself.
Interesting fact: to land on the moon, The Apollo guidance computer had only 4k of memory.</p>
<p>What are the differents types of memory?</p>
<img src="https://storage.googleapis.com/qwasar-public/s02_SE/memory_stack.png" width="600">
<p>An example of an implementation of memory. (Yes, there are differents implementation)</p>
<p>In this project, we will use the <code>heap</code> by recreating our own implementation of malloc().
But what is malloc?
Malloc is a dynamic memory allocator — it gives you a block of memory on the heap during run time. You want to use malloc when you don’t know the memory size during compile time. It’s also useful when you need to allocate memory greater than the size of the stack. More commonly, malloc is used for objects that must exist beyond the scope of the current block.</p>
<p>To reserve memory from the heap, we used to do reserve memory by calling the syscall <code>sbrk()</code>, but it has been deprecated on OS X. Today, we are going to call another syscall: <code>mmap()</code></p>
<p>It's straightforward to use:</p>
<pre class=" language-plain"><code class=" language-plain">#include &lt;unistd.h&gt;
#include &lt;stdio.h&gt;
#include &lt;sys/mman.h&gt;
#include &lt;string.h&gt;

void* my_malloc(int size) {
  return mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);;
}

int main(int ac, char **av) {
  char *src = "hello";
  char *dest = my_malloc(strlen(src) + 1);

  strcpy(dest, src);
  printf("s\n", dest);
  return 0;
}
</code></pre>
<p>Tada, we have done my_malloc(). Meh, where is the trick then...?</p>
<p>My_malloc is not a project about requesting memory. Calling mmap is very slow, we need to call it as minimum as we can.</p>
<p>If the user wants only 5 cells of memory, my_malloc will request a BIG chunk and divide it into smaller, so next time the user is calling my_malloc, it won't have to mmap again: It's a project about memory management.</p>
<p>Question are: how to keep track of memory sent to the user in order to reuse them? a struct? with a header?
and all our structs stored inside a linked list?</p>
<pre class=" language-plain"><code class=" language-plain">struct s_elem {
  struct s_elem* next;
  int            size;
  void*          ptr_for_the_user;
}
</code></pre>
<img src="https://storage.googleapis.com/qwasar-public/s02_SE/dlmalloc.png" width="600">
<p>There are multiple implementation of malloc. (dlmalloc - jemalloc - ...)</p>
<h2>Technical specifications</h2>
<p>Create your own implementation of the malloc families functions in order to allocate memory:</p>
<ul>
<li>my_malloc</li>
<li>my_free</li>
<li>my_calloc</li>
<li>my_realloc</li>
</ul>
<p><strong>Tip 00</strong>
Hash table are faster to search than a linked list.
What about balanced tree? <a href="https://en.wikipedia.org/wiki/Red-black_tree" target="_blank">Red and Black Tree</a> or <a href="https://en.wikipedia.org/wiki/AVL_tree" target="_blank">AVL Tree</a>?</p>
<p><strong>Tip 01</strong>
Hash table are interviews materials.
What is a hash function?
How to handle collisions?</p>

<p></p>
</div>

</div>
</div>
</div>
<div class="tab-pane" id="resources" role="tabpanel">
</div>
</div>
</div>
</div>
