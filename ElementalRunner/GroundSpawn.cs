using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GroundSpawn : MonoBehaviour
{

    public GameObject ground;

    public float x = 0;
    public float y = 5;
    public float z = 0;
    public float timePerSpawn = 3f;

    // Start is called before the first frame update
    void Start()
    {
        var newGround = GameObject.Instantiate(ground, new Vector3(x, y, z), Quaternion.identity);
    }

    // void Spawn() {
    //         var newGround = GameObject.Instantiate(ground, new Vector3(x, y, z), Quaternion.identity);
    //         if (timePerSpawn >= 1.5f) {
    //             timePerSpawn -= 0.2f;
    //         }
    //         Invoke("Spawn", timePerSpawn);
    // }

    void Update() {
        if (transform.position.x <= -8.7) {
            transform.position = new Vector3(10f, -4.55f, 0);
            var newGround = GameObject.Instantiate(ground, new Vector3(x, y, z), Quaternion.identity);
        }
    }

    // void OnTriggerEnter(Collider other) {
    //     Debug.Log("hit");
    //     if (other.gameObject.CompareTag("GroundDetect")) {
    //         var newGround = GameObject.Instantiate(ground, new Vector3(x, y, z), Quaternion.identity);
    //     }
    // }
}
