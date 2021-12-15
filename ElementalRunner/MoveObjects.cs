using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class MoveObjects : MonoBehaviour
{

    public bool isElem;
    public int objectElem;

    void Start() {
        // if (isElem) {
        //     if (objectElem == 1) {
        //         gameObject.GetComponent<SpriteRenderer>().color = Color.red;
        //     }
        //     else if (objectElem == 2) {
        //         gameObject.GetComponent<SpriteRenderer>().color = Color.blue;
        //     }
        //     else {
        //         gameObject.GetComponent<SpriteRenderer>().color = Color.white;
        //     }
        // }
    }
    // Update is called once per frame
    void Update()
    {
        transform.Translate(Vector2.left * PublicVars.worldSpeed * Time.deltaTime);
        if (transform.position.x <= -20) {
            Destroy(gameObject);
            
        }
    }

    private void OnCollisionEnter2D(Collision2D other) {
        if (other.gameObject.CompareTag("Player") && PublicVars.currElem != objectElem && isElem){
            PublicVars.killedByBarrier = true;
        }
    }
 }
