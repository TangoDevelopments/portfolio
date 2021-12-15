using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Enemy : MonoBehaviour
{
    AudioSource hit;
    public int elemToKill;
    // Start is called before the first frame update
    void Start()
    {
        GameObject hitGameObj = GameObject.Find("Hit");
        hit = hitGameObj.GetComponent<AudioSource>();
    }

    private void OnTriggerEnter2D(Collider2D other) {
        if (other.CompareTag("Bullet") && elemToKill == PublicVars.currElem) {
            hit.Play();
            Destroy(other.gameObject);
            Destroy(gameObject);
        }
        else if (other.CompareTag("Player")) {
            Destroy(other.gameObject);
            PublicVars.worldSpeed = 3f;
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        }
    }
}
