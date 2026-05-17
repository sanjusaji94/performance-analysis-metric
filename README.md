# Efficient Programs

This repository contains four exercises focused on performance analysis and optimization.

## Exercise 1 Summary

- Q1: Check which given programs are fast enough using wall-clock runtime.
- Q2: Identify which programs are CPU-bound from CPU usage and timing.
- Q3: Find CPU-bound programs that spend most time in user mode.
- Q4: Find CPU-bound programs that spend most time in system mode.
- Q5: Determine which program uses the most memory (peak RSS).
- Q6: Determine which program uses the most total CPU time.
- Q7: Use `gprof` to find the function that consumes the most runtime.
- Q8: Use `gprof` to find the function called most often.
- Q9: Use `gprof` call graph to find which function calls `sethi` most.
- Q10: Find which function `lessthan` calls most often.
- Q11: Use `gcov` to find the most frequently executed line in `solve`.

## Exercise 2 Summary

- Q1: Modify `list1()` to maximize instructions without passing a cycle limit.
- Q2: Modify `array1()` to match the new `list1()` computation and measure cycles.
- Q3: Modify `array2()` to increase cycles while staying under an instruction limit.
- Q4: Modify `list2()` to match the new `array2()` computation and compare cycles.

## Exercise 3 Summary

- Q1: Estimate L1 cache size by finding when L1 misses jump.
- Q2: Estimate cache line size from linear-access miss behavior.
- Q3: Design an experiment to estimate L2 cache size.
- Q4: Measure L2 access latency in linear vs random mode.
- Q5: Measure main memory latency (cycles and ns per access).
- Q6: Measure memory access with prefetcher help and estimate bandwidth.
- Q7: Analyze conflict misses to infer L1 associativity, ways, and sets.
- Q8: Estimate L1 TLB entries and coverage per entry using stride tests.
- Q9: Measure L1 TLB miss penalty with controlled parameters.
- Q10: Estimate L2 TLB capacity from miss-rate behavior.
- Q11: Measure cycles per access when L2 TLB misses are very high.

## Exercise 4 Summary

- Q1: Measure speedup and FLOPS from auto/manual vectorization in a data-parallel loop.
- Q2: Show code changes that block auto-vectorization in GCC and Clang.
- Q3: Show a loop that is vectorizable but not auto-vectorized by GCC.
- Q4: Measure vectorization speedup and FLOPS for a reduction workload.
- Q5: Measure vectorization speedup for a generation workload.
- Q6: Measure vectorization speedup for a conditional data-parallel loop.
- Q7: Find `n` values where vectorization overhead starts/stops paying off for `dp5`.
- Q8: Measure performance impact of `restrict` and compare auto vs noauto for `dp6`.
