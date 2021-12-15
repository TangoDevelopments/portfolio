using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bullet : MonoBehaviour
{
    Rigidbody2D rb;
    public int bulletSpeed = 1000;
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        rb.AddForce(new Vector2(bulletSpeed ,rb.velocity.y));
    }

    // Update is called once per frame
    void Update()
    {
        if (transform.position.x >= 20) {
            Destroy(gameObject);
        }
    }

    
}
