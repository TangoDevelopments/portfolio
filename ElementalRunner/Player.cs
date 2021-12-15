
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using System;


public class Player : MonoBehaviour
{

    // public float speedx;
    public float jumpspeedY;
    public float rollspeedY;
    public float distance = 0;

    //audio
    AudioSource _audioSource;
    public AudioSource fireShoot;
    public AudioSource waterShoot;
    public AudioSource iceShoot;
    public AudioSource jumpSound;
    public AudioSource landSound;
    public AudioSource deathSound;
    
    bool canJump;
    bool canRoll;
    float speed;

    public GameObject[] bullets;
    public Transform spawnPos;

    Rigidbody2D rb;
 
    //swipe detection
	private Vector2 fingerDownPos;
	private Vector2 fingerUpPos;

	public bool detectSwipeAfterRelease = false;

	public float SWIPE_THRESHOLD = 20f;

    public RuntimeAnimatorController[] controllers;

    private Animator animator;

    [SerializeField] GameObject gameOver;

    void Start()
    {
        animator = GetComponent<Animator>();
        animator.SetBool("Jumping", false);
        animator.SetBool("Shooting", false);
        PublicVars.currElem = UnityEngine.Random.Range(1, 4);
        if (PublicVars.currElem  == 1) {
            animator.runtimeAnimatorController = controllers[0];
        }
        else if (PublicVars.currElem  == 2) {
            animator.runtimeAnimatorController = controllers[1];
        }
        else {
            animator.runtimeAnimatorController = controllers[2];
        }

        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        if (PublicVars.killedByBarrier) {
            Debug.Log("1");
            deathSound.Play();
            Destroy(gameObject);
            gameOver.SetActive(true);
            Time.timeScale = 0f;
        }
        // animator.SetBool("Shooting", false);
        MovePlayer(speed);
        //left
        // if (Input.GetKeyDown(KeyCode.LeftArrow)){
        //     speed = -speedx;
        // }
        // if (Input.GetKeyUp(KeyCode.LeftArrow)){
        //     speed = 0;
        // }

        // //right
        // if (Input.GetKeyDown(KeyCode.RightArrow)){
        //     speed = speedx;
        // }
        // if (Input.GetKeyUp(KeyCode.RightArrow)){
        //     speed = 0;
        // }

        // for (int i = 0; i < Input.touchCount; ++i)
        // {
        //     Touch touch = Input.GetTouch(i);
        //     if (touch.phase == TouchPhase.Began)
        //     {
        //         fire();
        //     }
        // }

        //up
        if (Input.GetKeyDown(KeyCode.UpArrow)){
            // if (canJump) {
            //     rb.AddForce(new Vector2(rb. velocity.x, jumpspeedY));
            //     canJump = false;
            // }
            jump();
        }

        //down
        if (Input.GetKeyDown(KeyCode.DownArrow)){
            // if (canRoll) {
            //     rb.AddForce(new Vector2(rb. velocity.x, -rollspeedY));
            //     canRoll = false;
            // }
            roll();
        }

        if (Input.GetKeyDown("space")) {
            fire();
        }

        if (Input.GetKeyDown("q")) {
            fireElem();
        }

        if (Input.GetKeyDown("w")) {
            waterElem();
        }

        if (Input.GetKeyDown("e")) {
            iceElem();
        }

		foreach (Touch touch in Input.touches) {
			if (touch.phase == TouchPhase.Began) {
				fingerUpPos = touch.position;
				fingerDownPos = touch.position;
			}

			//Detects Swipe while finger is still moving on screen
			if (touch.phase == TouchPhase.Moved) {
				if (!detectSwipeAfterRelease) {
					fingerDownPos = touch.position;
					DetectSwipe ();
				}
			}

			//Detects swipe after finger is released from screen
			if (touch.phase == TouchPhase.Ended) {
				fingerDownPos = touch.position;
				DetectSwipe ();
			}
		}
    }

    void FixedUpdate() {
        animator.SetBool("Shooting", false);
    }



    void MovePlayer(float speed){
        rb.velocity = new Vector3(speed, rb.velocity.y, 0);
    }

    void OnCollisionEnter2D(Collision2D other){
        if (other.gameObject.CompareTag("Ground") && !canJump){
            if (PublicVars.score >= 4) {
                landSound.Play();
            }
            canJump = true;
            canRoll = true;
            animator.SetBool("Jumping", false);

        }
        if (other.gameObject.CompareTag("Bumper") || other.gameObject.CompareTag("Enemy") ){
            Debug.Log("2");
            deathSound.Play();
            Destroy(gameObject);
            gameOver.SetActive(true);
            Time.timeScale = 0f;
        }
    }

    // public void WalkLeft(){
    //     speed = -speedx;
    // }

    // public void WalkRight(){
    //     speed = speedx;
    // }

    // public void StopMoving(){
    //     speed = 0;
    // }

    public void fireElem(){
        // _audioSource.PlayOneShot(fireSound, 0.2f);
        
        animator.runtimeAnimatorController = controllers[0];
        PublicVars.currElem = 1;
    }

    public void waterElem(){
        // _audioSource.PlayOneShot(waterSound, 0.2f);
        animator.runtimeAnimatorController = controllers[1];
        PublicVars.currElem = 2;
    }

    public void iceElem(){
        // _audioSource.PlayOneShot(iceSound, 0.2f);
        animator.runtimeAnimatorController = controllers[2];
        PublicVars.currElem = 3;
    }

    public void jump(){
        if (canJump) {
            jumpSound.Play();
            rb.AddForce(new Vector2(rb.velocity.x, jumpspeedY));
            canJump = false;
            animator.SetBool("Jumping", true);
        }
        
    }

    public void roll(){
        if (canRoll) {
            rb.AddForce(new Vector2(rb.velocity.x, -rollspeedY));
            canRoll = false;
        }
        
    }

    public void fire() {
        if (PublicVars.currElem == 1) {
            fireShoot.Play();
        }
        else if (PublicVars.currElem == 2) {
            waterShoot.Play();
        }
        else {
            iceShoot.Play();
        }
        GameObject newBullet = Instantiate(bullets[PublicVars.currElem -1], spawnPos);
        animator.SetBool("Shooting", true);
    }
	void DetectSwipe ()
	{
		
		if (VerticalMoveValue () > SWIPE_THRESHOLD && VerticalMoveValue () > HorizontalMoveValue ()) {
			if (fingerDownPos.y - fingerUpPos.y > 0) {
				OnSwipeUp ();
			} else if (fingerDownPos.y - fingerUpPos.y < 0) {
				OnSwipeDown ();
			}
			fingerUpPos = fingerDownPos;
		} 
	}

	float VerticalMoveValue ()
	{
		return Mathf.Abs (fingerDownPos.y - fingerUpPos.y);
	}

	float HorizontalMoveValue ()
	{
		return Mathf.Abs (fingerDownPos.x - fingerUpPos.x);
	}

	void OnSwipeUp ()
	{	
        // if (canJump) {
        //     rb.AddForce(new Vector2(rb. velocity.x, jumpspeedY));
        //     canJump = false;
        // }
        jump();
	}

	void OnSwipeDown ()
	{
        // if (canRoll) {
        //     rb.AddForce(new Vector2(rb. velocity.x, -rollspeedY));
        //     canRoll = false;
        // }
        roll();
	}
}