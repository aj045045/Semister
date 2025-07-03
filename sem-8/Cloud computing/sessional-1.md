**Q1: Answer the following in brief (Any THREE) - [3 Marks Each]**

**1. What does C, A and P represent in CAP theorem?**
CAP Theorem, introduced by Eric Brewer, is fundamental in distributed systems. It states that it is impossible for a distributed data store to simultaneously provide more than two out of the following three guarantees:
- **Consistency (C):** All nodes see the same data at the same time. This means once data is written, all future reads return that same data.
- **Availability (A):** Every request gets a response, without guarantee of the most recent data.
- **Partition Tolerance (P):** The system continues to operate despite arbitrary message loss or failure of part of the system.

Most cloud databases (like Cassandra) trade consistency for availability and partition tolerance.

---

**2. Discuss 3 Vs related to Big Data in brief.**
The 3 Vs of Big Data describe its fundamental characteristics:
- **Volume:** Refers to the vast amounts of data generated every second (e.g., social media, IoT sensors). Storage and management require scalable cloud infrastructures.
- **Velocity:** The speed at which new data is generated and needs to be processed. Real-time systems like Kafka and Spark are essential.
- **Variety:** Data comes in different formats – structured (SQL), semi-structured (XML/JSON), and unstructured (videos, images).

---

**3. Discuss 3 scenarios of portability/interoperability in cloud computing.**
- **Cloud-to-cloud migration:** Moving an application from AWS to Azure requires portable configurations and containerized deployment.
- **Hybrid Cloud Operations:** Enterprises often integrate on-premise systems with cloud services, requiring APIs and standards that support interoperability.
- **Vendor Neutral Tools:** Use of Docker, Kubernetes, and Terraform ensures applications can run on multiple cloud platforms without rewriting code.

---

**Q2: Answer the following questions (Any THREE) - [5 Marks Each]**

**1. Differentiate between Vertical Scaling & Horizontal Scaling.**
| Feature              | Vertical Scaling                     | Horizontal Scaling                    |
|----------------------|--------------------------------------|---------------------------------------|
| Definition           | Increasing resources in a single machine | Adding more machines/nodes            |
| Implementation       | Upgrade RAM/CPU                      | Add more servers to the pool          |
| Downtime             | Often requires downtime              | Minimal or no downtime                |
| Cost                 | Expensive at scale                   | Cost-effective for large systems      |
| Example              | Upgrade from 4GB to 16GB RAM         | Add 3 web servers behind a load balancer |

Vertical scaling is easier initially, while horizontal scaling is preferred for high availability and large-scale distributed systems.

---

**2. Discuss classification of load balancing algorithms.**
Load balancing algorithms are used to distribute incoming network traffic across multiple servers:
- **Static Algorithms:**
  - *Round Robin:* Requests are distributed sequentially.
  - *Weighted Round Robin:* Each server is assigned a weight; higher-weight servers handle more requests.
- **Dynamic Algorithms:**
  - *Least Connection:* Routes traffic to the server with the fewest active connections.
  - *Resource Based:* Considers CPU, RAM usage before allocating requests.
- **Content-Based Routing (Layer 7):**
  - Routes traffic based on content (e.g., URL paths).

Choosing the right algorithm improves availability and performance.

---

**3. Discuss the model of CDN in detail.**
A **Content Delivery Network (CDN)** is a system of distributed servers that deliver content based on users' geographic locations.
- **Components:**
  - *Origin Server:* Hosts the original version of content.
  - *Edge Servers:* Cache content closer to users.
  - *DNS & Routing Logic:* Directs user requests to the nearest edge server.
- **Benefits:**
  - Reduces latency and server load.
  - Increases download speed.
  - Enhances scalability and availability.
  - Provides DDoS protection.
- **Examples:** Cloudflare, AWS CloudFront, Akamai.

---

**Q3: Answer the following in brief (Any THREE) - [2 Marks Each]**

**1. What role does the service level agreement (SLA) play in capacity planning?**
SLA defines the expected service performance (e.g., uptime, latency). It guides:
- How much capacity to provision.
- Ensures systems meet agreed performance targets.
- Reduces business risks and customer dissatisfaction.

---

**2. How persistence is implemented in load balancing?**
Persistence (also known as sticky sessions) ensures a client is always directed to the same server during a session. Techniques:
- **IP Hashing**
- **Session Cookie-based Routing**
Useful for applications where session data is stored locally (e.g., login sessions).

---

**3. What is the need for NoSQL database in cloud computing system?**
- Handles large volumes of unstructured/semi-structured data.
- Supports horizontal scaling and distributed architecture.
- Schema flexibility helps in agile development.
- Examples: MongoDB, Cassandra, DynamoDB.

---

