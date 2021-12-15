using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveGround : MonoBehaviour
{

    void Update()
    {
        transform.Translate(Vector2.left * PublicVars.worldSpeed * Time.deltaTime);
        if (transform.position.x <= -40) {
            Destroy(gameObject);
            
        }
    }
}
