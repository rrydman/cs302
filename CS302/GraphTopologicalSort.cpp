void graph::topSort()
{
	vertex v, w;
	for (int counter = 0; counter < num_vertices; counter++)
	{
		v = findVertexOfDegreeZero();
		if (v == not_a_vertex) // if nothing with indegree zero then you likely have a cycle
		{
			throw cycleFound();
		}
		v.topnum = counter;
		// for each w adjacent to v, degrement w.indegree

	}
}